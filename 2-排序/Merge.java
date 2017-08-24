
public class Merge {
	private static Comparable[] aux;  //归并所需的辅助数组
	
	public static void sort(Comparable[] a)
	{
		aux = new Comparable[a.length]; //一次性分配空间
		sort(a,0,a.length-1);
	}
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if( hi <= lo ) return;
		int mid = lo + (hi - lo)/2;
		sort(a,lo,mid); //将左半边排序
		sort(a,mid+1,hi); //将右半边排序
		merge(a,lo,mid,hi); //归并
	}
	private static void merge(Comparable[] a, int lo, int mid, int hi)
	{
		int i = lo, j = mid+1;
		
		for( int k = lo; k <= hi; k++ ) {
			aux[k] = a[k];	//将a[lo...hi]复制到aux[lo...hi]
		}
		
		for( int k = lo; k <= hi; k++ ) {
			if ( i > mid ) a[k] = aux[j++];	//左半边用尽 取右边元素
			else if ( j > hi ) a[k] = aux[i++]; //右半边用尽 取左边元素
			else if ( less(aux[j],aux[i]) ) a[k] = aux[j++];  //右半边的当前元素小于左半边的当前元素
			else a[k] = aux[i++];				//左半边的当前元素小于右半边的当前元素
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
