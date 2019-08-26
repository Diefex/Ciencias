package ordenamiento;

public class Insercion {

	public static void main(String[] args) {

		int[] a;

		for (int n = 10; n <= 500; n += 10) {

			a = new int[n];

			// relleno
			for (int i = 0; i < n; i++) {
				a[i] = n - i;
			}

			// ordenamiento
			long t0 = System.nanoTime();
			for (int i = 1; i < n; i++) {
				int j = i;
				int v = a[j];
				while (j > 0 && a[j - 1] > v) { // comparacion
					a[j] = a[j - 1]; // 1/2 intercambio
					j--;
				}
				a[j] = v; // 1/2 inetercambio
			}
			long t1 = System.nanoTime();

			// impresion
			System.out.println("N=" + n + ", tiempo: " + (t1 - t0) + "ns");
			for (int i : a) {
				// System.out.print(i + ",");
			}
		}
	}

}
