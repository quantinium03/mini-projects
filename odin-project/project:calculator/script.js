let firstOperator = '';
let secondOperator = '';
let currentOperation = null;
let resetScreen = false;

const numberBtn = document.querySelectorAll('.number');
const operatorBtn = document.querySelectorAll('.operator');
const equalBtn = document.querySelector('.equalBtn');
const dotBtn = document.querySelector('.dotBtn');
const clearBtn = document.querySelector('.clearBtn');
const backspaceBtn = document.querySelector('.backspaceBtn');
const backgroundBtn = document.querySelector('.BgBtn');
const operationOld = document.querySelector('.top-screen');
const operationNew = document.querySelector('.bottom-screen');

const addNumber = function(number) {
    if (operationNew.textContent === '0' || resetScreen) {
        newScreen()
    }
    operationNew.textContent += number
}

const addOperator = function(operator) {
    if (currentOperation !== null) {
        equateOperations()
    }
    firstOperator = operationNew.textContent
    currentOperation = operator;
    operationOld.textContent = `${firstOperator} ${currentOperation}`
    resetScreen = true
}

const newScreen = function() {
    resetScreen = false;
    operationNew.textContent = '';
}

const clearScreen = function() {
    operationNew.textContent = '0';
    operationOld.textContent = '';
    firstOperator = '';
    secondOperator = '';
    currentOperation = null;
}

const addDot = function() {
    if(resetScreen) newScreen()
    if (operationNew.textContent === '') {
        operationNew.textContent = '0';
    }
    if (operationNew.textContent.includes('.')) {
        return     }
operationNew.textContent += '.';

}

const equateOperations = function() {
    if (currentOperation === null || resetScreen) return;
    if (currentOperation === '/' && operationNew.textContent === '0') {
        alert(`You can't divide by 0`);
    }
    secondOperator = operationNew.textContent
    operationNew.textContent = Math.round(operate(currentOperation, firstOperator, secondOperator) * 1000) / 1000;
    operationOld.textContent = `${firstOperator} ${currentOperation} ${secondOperator} =`
    currentOperation = null
}

function removeOne() {
    operationNew.textContent = operationNew.textContent.toString().slice(0, -1)
}

const operationHandler = function(e) {
    if (e.key >= 0 && e.key <= 9) addNumber(e.key)
    if (e.key === '.') addDot()
    if (e.key === '=' || e.key === 'Enter') equateOperations()
    if (e.key === 'Backspace') removeOne()
    if (e.key === 'Escape') clearScreen()
    if (e.key === '+' || e.key === '-' || e.key === '*' || e.key === '/' || e.key === '%')
        addOperator(e.key);
}


function add(a, b) {
    return a + b
}

function subtract(a, b) {
    return a - b
}

function multiply(a, b) {
    return a * b
}

function divide(a, b) {
    return a / b
}

function remainder(a, b) {
    return a % b;
}

function operate(operator, a, b) {
    a = Number(a)
    b = Number(b)
    switch (operator) {
        case '+':
            return add(a, b)
        case '-':
            return subtract(a, b)
        case '*':
            return multiply(a, b)
        case '/':
            if (b === 0) return null
            else return divide(a, b)
        case '%':
            return remainder(a, b)
        default:
            return null
    }
}


window.addEventListener('keydown', operationHandler);
equalBtn.addEventListener('click', equateOperations);
clearBtn.addEventListener('click', clearScreen);
backspaceBtn.addEventListener('click', removeOne);
dotBtn.addEventListener('click', addDot);

numberBtn.forEach((button) =>
    button.addEventListener('click', () => addNumber(button.textContent)));

operatorBtn.forEach((button) =>
    button.addEventListener('click', () => addOperator(button.textContent)));


