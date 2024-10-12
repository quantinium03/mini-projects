const leapYears = function(year) {
    if ((year % 400 ===0) || (year % 100 !== 0 && year % 4 === 0)) {
        return 'yes';
    }else return 'no';
}

module.exports = leapYears;
