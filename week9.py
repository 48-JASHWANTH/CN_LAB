
import math

def main():
    p = int(input("Enter a prime number (p): "))
    q = int(input("Enter another prime number (q): "))
    n = p * q  # Modulus for public and private keys
    phi = (p - 1) * (q - 1)  # Euler's totient function
    # Choose e such that 1 < e < phi and gcd(e, phi) = 1
    e = 7
    while e < phi:
        if math.gcd(e, phi) == 1:
            break
        else:
            e += 1
    # Calculate d such that (d * e) % phi = 1
    k = 1
    while True:
        if (1 + k * phi) % e == 0:
            d = (1 + k * phi) // e
            break
        k += 1
    # Input a message to encrypt
    msg = int(input("Enter a message (as a number): "))
    print("Message:", msg)
    # Encrypt the message
    c = pow(msg, e, n)  # c = (msg^e) % n
    print("Encrypted data:", c)
    # Decrypt the message
    m = pow(c, d, n)  # m = (c^d) % n
    print("Decrypted data:", m)

if __name__ == "__main__":
    main()