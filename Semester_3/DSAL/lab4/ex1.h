int bin_search(int low, int high, int item, int a[])
{
	int mid;
	if(low>high)
		return (-1);
	else
	{
		mid = (low+high)/2;
		if(item==a[mid])
			return(mid);
		else if(item<a[mid])
			return(bin_search(low, mid-1, item, a));
		else 
			return(bin_search(mid+1, high, item, a));
	}
}