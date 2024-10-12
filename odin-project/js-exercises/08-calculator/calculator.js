const add = function(a, b) {
    return a + b;
}

const subtract = function(a, b) {
    return a - b;
}

const division = function(a , b) {
    return a / b;
}

const factorial = function (n) {
  if (n === 0) return 1;
  let product = 1;
  for (let i = n; i > 0; i--) {
    product *= i;
  }
  return product;
};

const power = function (a, b) {
  return Math.pow(a, b);
};

module.exports = {
  add,
  subtract,
  division, 
  power,
  factorial,
};
