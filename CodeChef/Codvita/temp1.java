import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;

class temp {
	private static final int BUFFER_SIZE = 1;
	static URL url;
	static URLConnection conn;
	static BufferedInputStream in;
	static RandomAccessFile raf;
	public static void main(String S[]){
	 try{
	 //connection to the remote object referred to by the URL.
        url = new URL("http://www.hdpicswale.in/download-file/assets/upload/hollywood/kristen-stewart-145/download-hd-photo-of-kristen-stewart-3105.jpeg");
        // connection to the Server
        conn = (HttpURLConnection) url.openConnection();

        // get the input stream from conn
        in = new BufferedInputStream(conn.getInputStream());

        // save the contents to a file
        raf = new RandomAccessFile("output.jpg","rw");


        byte[] buf = new byte[ BUFFER_SIZE ];
        int read;

        while( ((read = in.read(buf,0,BUFFER_SIZE)) != -1) )
    {

            raf.write(buf,0,BUFFER_SIZE);
    }

    } catch (IOException e ) {

    }
    finally {

    }
    }
	
}
