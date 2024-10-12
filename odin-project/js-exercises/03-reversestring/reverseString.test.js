const reverseString = require('./reverseString');

describe('reverseString', () => {
    test('reverses a string',  () => {
        expect(reverseString('Hello World')).toEqual('dlroW olleH');
    });

    test('reverses odin project', () => {
        expect(reverseString('odin project')).toEqual('tcejorp nido');
    });

    test('reverses javascript', () => {
        expect(reverseString('javascript')).toEqual('tpircsavaj');
    });

    test('reverse ""', () => {
        expect(reverseString('')).toEqual('');
    });
});
