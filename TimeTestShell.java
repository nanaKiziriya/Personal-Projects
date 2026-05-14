class TimeTestShell{
    public static void main(String[] args) {
        int size = 1000;
        Random r = new Random();
        int[] arr2 = r.ints(10,0,size).toArray();
        int[] arrN = arr2.clone();
        
        long startTime = System.nanoTime();
        // test 1
        long endTime = System.nanoTime();
        long timeElapsed2Split = endTime - startTime;
        System.out.println("test 1: " + timeElapsed2Split); // in nanoseconds

        startTime = System.nanoTime();
        // test 2
        endTime = System.nanoTime();
        long timeElapsedNSplit = endTime - startTime;
        System.out.println("test 2: " + timeElapsedNSplit); // in nanoseconds

    }
}
