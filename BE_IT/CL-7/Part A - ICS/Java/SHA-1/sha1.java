import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

class sha1
{
    public static void main(String ar[]) throws NoSuchAlgorithmException
    {
        Scanner s = null;
        try 
        {
            //initialize Scanner object
            s = new Scanner(System.in);

            //Enter Message
            System.out.print("Enter the message: ");
            String text = s.next();

            //create StringBuffer object for storing sha1 hash code
            StringBuffer sha = new StringBuffer();

            //initialize Message digest object and set algorithm to SHA1 in getinstance method
            MessageDigest digest = MessageDigest.getInstance("SHA-1");
            digest.update(text.getBytes());

            //store the text file in byte array
            byte hash[] = digest.digest();

            //convert byte into appropriate hex code and append it onto the StringBuffer Object
            for(byte b : hash)
            {
                sha.append(String.format("%02x", b & 0xff));
            }

            //print the SHA1 hash, i.e SHA1 message digest
            System.out.println("SHA1 hash: "+sha);
        }
        finally
        {
            if(s!=null)
            {
                s.close();
            }
        }
    }
}