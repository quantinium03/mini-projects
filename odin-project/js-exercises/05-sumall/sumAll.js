const sumAll = function(first, last) {

    let sum = 0;
    if (!Number.isInteger(first) || !Number.isInteger(last) || first < 0 || last < 0) return "ERROR";
    if (first > last) {
        const temp = first;
        first = last;
        last = temp;
    };

    for (let i = first; i <= last; i++) {
        sum += i;
    };
    return sum;
};

module.exports = sumAll;
