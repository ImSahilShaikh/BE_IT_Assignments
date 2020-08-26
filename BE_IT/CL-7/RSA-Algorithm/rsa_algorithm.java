import java.util.Scanner;

class rsa
{
    static double gcd(double num1, double num2)
    {
        double temp = 0;
        while(true)
        {
            temp = num1 % num2;
            if(temp == 0)
            {
                return num2;
            }
            num1 = num2;
            num2 = temp;
        }
    }
    public static void main(final String args[]) {
        Scanner s = null;
        try {
            s = new Scanner(System.in);
            final double p = 17, q = 11;
            final double n = p * q;

            double e = 7;

            final double phi = (p - 1) * (q - 1);

            while (e < phi) {
                // double check = gcd(e, phi);
                if (gcd(e, phi) == 1)
                    break;
                else
                    e++;
            }

            System.out.print("Please enter a number you want to Encrypt: ");
            final double plain_text = s.nextDouble();

            final double d = (1 / e) % phi;

            double encry = Math.pow(plain_text, e);
            double decry = Math.pow(encry, d);

            encry %= n;
            decry %= n;
            
            System.out.println("The Encrypted text is: "+ Math.round(encry));
            System.out.println("The Decrypted text is: "+ Math.round(decry));
        }
        finally
        {
            if(s != null)
            {
                s.close();
            }
        }
    }
}
