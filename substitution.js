const key = 46;


function getASCIICode(_char, position) {
    return _char.charCodeAt(position) & 255;
}


function ecryptASingleByte(plainbyte) {
    return (plainbyte + key) % 256;
}


function decryptASingleByte(cipherbyte) {
    return (256 + (cipherbyte - key)) % 256;
}


function encrypt(plaintext) {
    let ciphertext = '';
    for (let i = 0; i < plaintext.length; i++) {
        let cipherbyte = ecryptASingleByte(getASCIICode(plaintext, i));
        ciphertext += cipherbyte.toString(16);
    }
    return ciphertext;
}


function decrypt(ciphertext) {
    let plaintext = '';
    for (let i = 0; i < ciphertext.length; i += 2) {
        let cipherbyte = parseInt(ciphertext[i] + ciphertext[i + 1], 16);

        let plainbyte = decryptASingleByte(cipherbyte);
        plaintext += String.fromCharCode(plainbyte);
    }
    return plaintext;
}


let plaintext = 'Hello World!';

let ciphertext = encrypt(plaintext);
console.log('ciphertext: ' + ciphertext);
let decrypted = decrypt(ciphertext);
console.log('decrypted: ' + decrypted);

/* Execution example:
 * $ node substitution.js
 * ciphertext: 76939a9a9d4e859da09a924f
 * decrypted: Hello World!
 */
