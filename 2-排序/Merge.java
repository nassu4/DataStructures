
public class Merge {
	private static Comparable[] aux;  //�鲢����ĸ�������
	
	public static void sort(Comparable[] a)
	{
		aux = new Comparable[a.length]; //һ���Է���ռ�
		sort(a,0,a.length-1);
	}
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if( hi <= lo ) return;
		int mid = lo + (hi - lo)/2;
		sort(a,lo,mid); //����������
		sort(a,mid+1,hi); //���Ұ������
		merge(a,lo,mid,hi); //�鲢
	}
	private static void merge(Comparable[] a, int lo, int mid, int hi)
	{
		int i = lo, j = mid+1;
		
		for( int k = lo; k <= hi; k++ ) {
			aux[k] = a[k];	//��a[lo...hi]���Ƶ�aux[lo...hi]
		}
		
		for( int k = lo; k <= hi; k++ ) {
			if ( i > mid ) a[k] = aux[j++];	//�����þ� ȡ�ұ�Ԫ��
			else if ( j > hi ) a[k] = aux[i++]; //�Ұ���þ� ȡ���Ԫ��
			else if ( less(aux[j],aux[i]) ) a[k] = aux[j++];  //�Ұ�ߵĵ�ǰԪ��С�����ߵĵ�ǰԪ��
			else a[k] = aux[i++];				//���ߵĵ�ǰԪ��С���Ұ�ߵĵ�ǰԪ��
		}
	}
	private static boolean less(Comparable v, Comparable w)
	{
		return v.compareTo(w) < 0;
	}
	private static boolean isSorted(Comparable[] a)
	{
		int N = a.length;
		for( int i = 1; i < N; i++ ) {
			if( less(a[i],a[i-1]) ) return false;
		}
		return true;
	}
	private static void show(Comparable[] a)
	{
		int N = a.length;
		for( int i = 0; i < N; i++ ) {
			StdOut.print(a[i]+ " ");
		}
		StdOut.println();
	}
	public static void main(String[] args)
	{
		String[] a = In.readStrings();
		sort(a);
		assert isSorted(a);
		show(a);
	}
}
