const ffmpeg = require('fluent-ffmpeg');
const ffmpegInstaller = require('@ffmpeg-installer/ffmpeg');

ffmpeg.setFfmpegPath(ffmpegInstaller.path);

ffmpeg('./videos/input.mp4', { timeout: 432000 }).addOptions([
    '-hls_time 10',
    '-hls_list_size 0',
    '-f hls'
]).output('./videos/output.m3u8').on('end', () => {
    console.log('end');
}).run();
