import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	static String ReadLn(int maxLg) // utility function to read from stdin
	{
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		String line = "";

		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n'))
					break;
				lin[lg++] += car;
			}
		} catch (IOException e) {
			return (null);
		}

		if ((car < 0) && (lg == 0))
			return (null);
		return (new String(lin, 0, lg));
	}

	static class Num {
		public BigInteger num, den;
		void reduce() {
			BigInteger cd = den.gcd(num);
			num = num.divide(cd);
			den = den.divide(cd);
		}

		BigInteger stirlingN2(BigInteger n, BigInteger k) {
			if (n == k)
				return BigInteger.valueOf(1);
			if (k == BigInteger.ZERO)
				return BigInteger.ZERO;
			BigInteger[] dp = new BigInteger[n.intValue() - k.intValue() + 1];

			for (int i = 0; i < dp.length; i++) {
				dp[i] = BigInteger.ONE;
			}

			for (int i = 2; i <= k.intValue(); ++i) {
				for (int j = 1; j <= n.intValue() - k.intValue(); ++j) {
					dp[j] = dp[j].add(dp[j - 1].multiply(BigInteger.valueOf(i)));
				}
			}

			return dp[n.intValue() - k.intValue()];
		}
	}

	public static void main(String args[]) // entry point from OS
	{
		String input;
		StringTokenizer idata;
		BigInteger n, m, k;
		Num nu = new Num();
		while (true) {
			input = ReadLn(255);
			idata = new StringTokenizer(input);
			n = BigInteger.valueOf(Integer.parseInt(idata.nextToken()));
			m = BigInteger.valueOf(Integer.parseInt(idata.nextToken()));
			k = BigInteger.valueOf(Integer.parseInt(idata.nextToken()));
			if (n == BigInteger.ZERO && m == BigInteger.ZERO && k == BigInteger.ZERO) {
				break;
			}
			if (k.intValue() == 0 && m.intValue() == 0){
				System.out.println("1/1");
				continue;
			}
			if (k.intValue() > n.intValue() || k.intValue() > m.intValue() || m.intValue() == 0) {
				System.out.println("0/1");
				continue;
			}
			nu.num = BigInteger.ONE;
			nu.den = BigInteger.ONE;
			for (int i = 0; i < k.intValue(); i++) {
				nu.num = nu.num.multiply((n.subtract(BigInteger.valueOf(i))));
				nu.den = nu.den.multiply(n);
			}
			nu.den = nu.den.multiply(n.pow(m.intValue() - k.intValue()));
			nu.num = nu.num.multiply(nu.stirlingN2(m, k));
			if (nu.num == BigInteger.ZERO)
				System.out.println("0/1");
			else {
				nu.reduce();
				System.out.print(nu.num.toString());
				System.out.print("/");
				System.out.println(nu.den.toString());
			}
		}
	}
}
/*
10 0 0
10 12 10
3 2 0
4 2 4
1 1 1
2 3 3
3 2 3
*/