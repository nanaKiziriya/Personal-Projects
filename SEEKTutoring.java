class SEEKTutoring {
    public static void main(String[] args) {
        
        int totalCents;
        
        for(int i=0; i<args.length; i++){ // for every file
            Scanner sc = new Scanner(new File(args[i])); // read the file
            // e.g. file: $279.05 $100.56
            while(sc.hasNext()){
                String money = sc.next(); //$279.50
                money=money.replace("$",""); //279.50
                String amnts = money.split("."); //{"279","50"}
                int dollar = Integer.parseInt(amnts[0])*100;
                int cents = Integer.parseInt(amnts[1]);
                totalCents += dollar+cents;
            }
            
            sc.close();
            
        }
        
        System.out.printf("$%d.%d",totalCents/100,totalCents%100);
    }
}
