
 public static boolean isNonterminating(int a,int b){
        try{
            BigDecimal bigA=new BigDecimal(a);
            BigDecimal bigB=new BigDecimal(b);
            bigA.divide(bigB);
            return false;
        }catch(Exception e){
            return true;
        }
    }
