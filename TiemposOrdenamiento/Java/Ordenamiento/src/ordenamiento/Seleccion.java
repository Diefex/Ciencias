package ordenamiento;

public class Seleccion {

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
			for (int i = 0; i < n - 1; i++) {
				min = i;
				for (int j = i + 1; j < n; j++) {
					if (a[j] < a[min]) { // comparacion
						min = j;
					}
				}
				// intercambio
				int aux = a[min];
				a[min] = a[i];
				a[i] = aux;
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
