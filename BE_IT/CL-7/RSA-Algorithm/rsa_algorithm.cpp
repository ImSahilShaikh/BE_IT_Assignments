#include<bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2)
{
    int temp = 0;
    while (true)
    {
        temp = n1 % n2;
        if (temp == 0)
        {
            return n2;
        }
        n1 = n2;
        n2 = temp;
    }
}

int main()
{
    //These are two input prime numbers,
    double p = 17, q = 11;

    //n is used as modulus for both public and private keys
    double n = p * q;

    //e stands for encrypt
    double e = 7;

    //phi is eulers totient function
    double phi = (p - 1) * (q - 1);

    //e must be coprime of phi and smaller than it
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    double plain_text = 88;

    cout << "Plain text is: " << plain_text << endl;

    double d = fmod((1/e),phi);

    double encrypt = pow(plain_text,e);
    double decrypt = pow(encrypt,d);
    encrypt = fmod(encrypt,n);
    decrypt = fmod(decrypt,n);

    cout<<"Encrypted text is: "<<encrypt<<endl;
    cout<<"Decrypted text is: "<<decrypt<<endl;

    return 0;
}
