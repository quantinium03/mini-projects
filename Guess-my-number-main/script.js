'use strict';

let guessingNumber = Math.trunc(Math.random() * 20 ) + 1;
let score = 20, highscore = 0;

const displayMessage = function(message) {
    document.querySelector('.message').textContent = message;
}


document.querySelector('.check').addEventListener('click', function () {
  const guess = Number(document.querySelector('.guess').value);

    if (!guess) {
        displayMessage("Wrong Input");
    }
    else if (guessingNumber === guess) {
        displayMessage("Congrat's You won")
        if (score > highscore){
            highscore = score
            document.querySelector('.highscore').textContent = highscore;
        }

        document.querySelector('body').style.backgroundColor = '#60b347';
    }
    else if(guessingNumber !== guess ) {
        if (score > 1) {
            displayMessage(guess > guessingNumber ? "Too High" : "Too Low");
            score--;
            document.querySelector('.score').textContent = score;
        }
        else {
            displayMessage("You Lose")
            document.querySelector('.score').textContent = 0;
        }
    }
});

document.querySelector('.again').addEventListener('click',function() {
    document.querySelector('body').style.backgroundColor = "#222"
    guessingNumber = Math.trunc(Math.random() * 20 ) + 1;
    score = 20;
    highscore = 0;

    document.querySelector('.message').textContent = "Start guessing";
    document.querySelector('.score').textContent = score;
    document.querySelector('.highscore').textContent = highscore;
    document.querySelector('.guess').textContent = '';
});