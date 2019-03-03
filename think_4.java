/*
 题意：用快排的思想，找出一个数组中第K大的数

 */
public static int findKth(int[] a, int n, int K){
        int ans=0;
        int left=0,right=n-1;
        int index=n-K;
        while(true){
        int beg=left,end=right;
        int tmp=a[beg];
        while(beg<end){
        while(beg<end &&a[end]>=tmp){
        end--;
        }
        a[beg]=a[end];
        while(beg<end &&a[beg]<=tmp){
        beg++;
        }
        a[end]=a[beg];
        }
        a[beg]=tmp;
        System.out.print("排序:");
        for(int i=0;i<n;i++){
        System.out.print(i+"->"+a[i]+"、");
        }
        System.out.println();
        System.out.println("中间值："+tmp+"下标:"+beg);
        if(beg==index){
        ans=a[beg];
        break;
        }else if(beg<index){
        left=beg+1;
        right=right;
        }else if(beg>index){
        left=left;
        right=beg-1;
        }
        }
        return ans;
        }