package ordenamiento;

public class Burbuja {

	public static void main(String[] args) {

		int[] a;

		for (int n = 10; n <= 500; n += 10) {

			a = new int[n];

			// relleno
			for (int i = 0; i < n; i++) {
				a[i] = i + 1;
			}

			int min;

			// ordenamiento
			long t0 = System.nanoTime();
			for (int i = n; i >= 0; i--) {
				for (int j = 1; j < i; j++) {
					if (a[j - 1] > a[j]) { // comparacion
						// intercambio
						int aux = a[j - 1];
						a[j - 1] = a[j];
						a[j] = aux;
					}
				}
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
