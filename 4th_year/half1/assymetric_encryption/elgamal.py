# coding: utf8
import random

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def is_prime(num):
    if num == 2:
        return True
    if num < 2 or num % 2 == 0:
        return False
    for n in xrange(3, int(num ** 0.5) + 2, 2):
        if num % n == 0:
            return False
    return True


def generate_keys(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError('Both numbers must be prime.')
    elif p == q:
        raise ValueError('p and q cannot be equal')
    elif q > p:
        raise ValueError('q must be less than p (q < p)')

    x = random.randrange(1, p)  # 0 < x < p
    y = q ** x % p

    k = random.randrange(1, p-1)
    g = gcd(k, p-1)
    while g != 1:
        k = random.randrange(1, p-1)
        g = gcd(k, p-1)

    return (p, q, x, y, k)

def encrypt(composite_key, plaintext):
    p, q, x, y, k = composite_key

    a = (q ** k) % p
    b = [((y ** k) * ord(char)) % p for char in plaintext]

    return (p, x, a, b)


def decrypt(ciphertext):
    p, x, a, b = ciphertext
    for each in b:
        each = chr((each * pow(a, p-1-x)) % p)
    return each

def main():
    p = int(raw_input('input p: '))
    q = int(raw_input('input q: '))
    composite_key = generate_keys(p, q)
    print composite_key
    msg = raw_input('input msg: ')
    ciphertext = encrypt(composite_key, msg)
    print ciphertext


if __name__ == '__main__':
    main()