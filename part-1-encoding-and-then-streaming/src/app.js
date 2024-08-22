const path = require('path');
const fs = require('fs');
const express = require('express');
const { exec } = require('child_process');
const hls = require('hls-server');

const app = express();
const port = 7777;

// Serve the client HTML file
app.get('/', (req, res) => {
    res.status(200).sendFile(path.join(__dirname, 'client.html'));
});

// Set up the HLS server
const server = app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});

new hls(server, {
    provider: {
        exists: (req, cb) => {
            const filePath = path.join(__dirname, req.url);
            fs.access(filePath, fs.constants.F_OK, (err) => {
                cb(null, !err);
            });
        },
        getManifestStream: (req, cb) => {
            const filePath = path.join(__dirname, req.url);
            const stream = fs.createReadStream(filePath);
            cb(null, stream);
        },
        getSegmentStream: (req, cb) => {
            const filePath = path.join(__dirname, req.url);
            const stream = fs.createReadStream(filePath);
            cb(null, stream);
        }
    }
});

// Start live encoding with FFmpeg
const ffmpegCommand = `ffmpeg -i ./videos/input.mp4 -c:v libx264 -preset fast -b:v 3000k -c:a aac -b:a 128k -f hls -hls_time 10 -hls_list_size 0 -hls_segment_filename 'videos/segment%d.ts' -hls_flags delete_segments http://localhost:7777/live/stream.m3u8`;

exec(ffmpegCommand, (error, stdout, stderr) => {
    if (error) {
        console.error(`Error executing FFmpeg: ${error.message}`);
        return;
    }
    if (stderr) {
        console.error(`FFmpeg stderr: ${stderr}`);
        return;
    }
    console.log(`FFmpeg stdout: ${stdout}`);
});
