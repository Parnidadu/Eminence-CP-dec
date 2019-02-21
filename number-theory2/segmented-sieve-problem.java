import java.io.*;
import java.util.*;
public class Main {

	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public String next() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == ' ')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}

	public static void main(String[] args) throws IOException{
		// Write your code here
      Reader s = new Reader();
      //Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        ArrayList<Integer> list = seive();
        for (int i = 1; i <= t; i++) {
            long l = s.nextLong();
            long r = s.nextLong();
            printprimes(l, r,list);
        }
    }

    public static ArrayList<Integer> seive() {
        boolean[] isprime = new boolean[100001];
        for (int i = 0; i < isprime.length; i++) {
            isprime[i] = true;
        }
        for (int i = 2; i * i <= isprime.length; i++) {
            if (isprime[i] == true) {
                for (int j = i * i; j < isprime.length; j += i) {
                    isprime[j] = false;
                }
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        list.add(2);
        for(int i=3;i<isprime.length;i+=2){
            if(isprime[i]==true){
                list.add(i);
            }
        }
        return list;

        
    }

    public static void printprimes(long l, long r, ArrayList<Integer> list) {
        boolean[] isprime = new boolean[(int)(r-l+1)];
        for (int i = 0; i <= r - l; i++) {
            isprime[i] = true;
        }
        for (int i = 0; list.get(i) * (long) list.get(i) <= r; i++) {
            int currprime = list.get(i);
            long base = (l / currprime) * currprime;
            if (base < l) {
                base += currprime;
            }
            for (long j = base; j <= r; j += currprime) {
                isprime[(int)(j -l)] = false;

            }
            if (base == currprime) {
                isprime[(int)(base - l)] = true;
            }
        }
        for (int i = 0; i <= r - l; i++) {
            if (isprime[i] == true) {
                System.out.println(i+l);
            }
        }


	}

}
