const leapYears = require('./leapYears.js');

describe('Tells if a year is a leap year or not', () => {
    test('if year 2004 is leap year on not', () => {
        expect(leapYears(2004)).toEqual('yes');
    })
    test('if year 1992 is leap year on not', () => {
        expect(leapYears(1992)).toEqual('yes');
    })
    test('if year 3016 is leap year on not', () => {
        expect(leapYears(3016)).toEqual('yes');
    })
    test('if year 1000 is leap year on not', () => {
        expect(leapYears(1000)).toEqual('no');
    })
    test('if year 500 is leap year on not', () => {
        expect(leapYears(500)).toEqual('no');
    });
});
