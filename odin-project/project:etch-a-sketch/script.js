let currentSize = 16;
let mode = 'color';
let currentColor = 'rgb(0, 0, 0)';

const setColor = function(newColor) {
    currentColor = newColor;
}

const setCurrentSize = function(newSize) {
    currentSize = newSize;
}
const updateSize = function(value) {
    sizeValue.innerHTML = `${value} x ${value}`;
}

const clearAll = function() {
    grid.innerHTML = '';
    makeGrid(currentSize);
}


const changeSize = function(value) {
    setCurrentSize(value);
    updateSize(value);
    clearAll();
};

const makeGrid = function(size) {
    grid.style.gridTemplateColumns = `repeat(${size}, 1fr)`;
    grid.style.gridTemplateRows = `repeat(${size}, 1fr)`;

    for (let i = 0; i < size * size; i++) {
        const gridEl = document.createElement('div');
        gridEl.classList.add('grid-element');
        gridEl.addEventListener('mouseover', changeColor);
        gridEl.addEventListener('mousedown', changeColor);
        grid.appendChild(gridEl);
    }
};


const changeColor = function(e) {
    if (e.type === 'mouseover' && !mousePress) {
        return;
    }
    if (mode === 'random') {
        const redRatio = Math.floor(Math.random() * 255);
        const greenRatio = Math.floor(Math.random() * 255);
        const blueRatio = Math.floor(Math.random() * 255);

        e.target.style.backgroundColor = `rgb(${redRatio}, ${greenRatio}, ${blueRatio})`;
    }
    else if (mode === 'color') {
        e.target.style.backgroundColor = currentColor;
    }
    if (mode === 'eraser') {
        e.target.style.backgroundColor = `rgb(254, 254, 254)`;
    }
}

const setMode = function(newMode) {
    if (mode === 'color') {
        colorBtn.classList.remove('active');
    }
    else if (mode === 'random') {
        randomBtn.classList.remove('active');
    }
    else if (mode === 'eraser') {
        eraserBtn.classList.remove('active');
    }

    if (newMode === 'color') {
        colorBtn.classList.add('active');
    }
    else if (newMode === 'random') {
        randomBtn.classList.add('active');
    }
    else if (newMode === 'eraser') {
        eraserBtn.classList.add('active');
    }
    mode = newMode;
}

window.onload = () => {
    makeGrid(currentSize);
    setMode(mode);
}
const colorPanel = document.getElementById('color-panel');
const colorBtn = document.getElementById('color-mode');
const randomBtn = document.getElementById('random-mode');
const eraserBtn = document.getElementById('eraser');
const clearBtn = document.getElementById('clear-all');
const sizeValue = document.getElementById('size-value');
const sizeSlider = document.getElementById('slider');
const grid = document.getElementById('grid');

colorPanel.oninput = (e) => setColor(e.target.value);
colorBtn.onclick = () => setMode('color');
randomBtn.onclick = () => setMode('random');
eraserBtn.onclick = () => setMode('eraser');
clearBtn.onclick = () => clearAll();
sizeSlider.onmousemove = (e) => updateSize(e.target.value);
sizeSlider.onchange = (e) => changeSize(e.target.value);

let mousePress = false;
document.body.onmousedown = () => (mousePress = true);
document.body.onmouseup = () => (mousePress = false);


