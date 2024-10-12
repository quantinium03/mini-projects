const removeFromArray = require('./removeFromArray.js');

describe('removeFromArray', () => {
    test('remove 3 from [1,2,3,4]', () => {
        expect(removeFromArray([1, 2, 3, 4], 3)).toEqual([1, 2, 4]);
    })
    test('remove 1 from [1,2,3,4]', () => {
        expect(removeFromArray([1, 2, 3, 4], 1)).toEqual([2, 3, 4]);
    })
    test('remove 2 from [1,2,3,4]', () => {
        expect(removeFromArray([1, 2, 3, 4], 2)).toEqual([1, 3, 4]);
    })
    test('remove 4 from [1,2,3,4]', () => {
        expect(removeFromArray([1, 2, 3, 4], 4)).toEqual([1, 2, 3]);
    })

})
