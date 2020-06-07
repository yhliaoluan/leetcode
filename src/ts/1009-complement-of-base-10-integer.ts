/**
 * convert a base 10 number to base 2
 */
function toBaseTwo(N: number): string {
  let result: string = '';
  while (N !== 0) {
    result = (N % 2 === 0 ? '0' : '1') + result;
    N = Math.floor(N / 2);
  }
  return result === '' ? '0' : result;
}

/**
 * complement a bitwise string. E.g. '100' to '001'
 */
function stringComplement(str: string): string {
  let result: string = '';
  for (let i = 0; i < str.length; i++) {
    result += str[i] === '0' ? '1' : '0';
  }
  return result;
}

/**
 * bitwise string to base 10 number.
 */
function toBaseTen(baseTwo: string): number {
  let result = 0;
  let factor = 0;
  for (let i = baseTwo.length - 1; i >= 0; i--) {
    if (baseTwo[i] == '1') {
      result += Math.pow(2, factor);
    }
    factor += 1;
  }
  return result;
}

function bitwiseComplement(N: number): number {
  return toBaseTen(stringComplement(toBaseTwo(N)))
};

console.log(bitwiseComplement(0))
console.log(bitwiseComplement(7))
console.log(bitwiseComplement(10))
