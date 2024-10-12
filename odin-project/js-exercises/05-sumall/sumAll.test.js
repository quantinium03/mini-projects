const sumAll = require('./sumAll.js')

describe('sumAll', () => {
    test('Sum 1 and 4', () => {
        expect(sumAll(1,4)).toEqual(10);
    })
    test('Sum 1 and 10', () => {
        expect(sumAll(1,10)).toEqual(55);
    })
    test('Sum 1 and 20', () => {
        expect(sumAll(1,20)).toEqual(210);
    })
    test('Sum 1 and 3', () => {
        expect(sumAll(1,3)).toEqual(6);
    })
    test('Sum 1 and 15', () => {
        expect(sumAll(1,15)).toEqual(120);
    })
})
