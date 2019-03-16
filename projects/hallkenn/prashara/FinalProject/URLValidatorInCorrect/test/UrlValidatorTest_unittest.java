

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	
	   
	   
	   
   }
   public void testYourFirstPartition(){
		 //You can use this function to implement your Second Partition testing	   
	   System.out.println("\nTest Schemes in Urls.\n");
     int pFail=0, pPass=0,fFail=0, fPass=0;   // pFail = positive test fail , pPass = positive test pass
     // fFail = negative test fail, fPass = negative test fail.
    
     UrlValidator url = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

     String posTest[] = {
  	   "http://",
         "ftp://",
         "h3t://",
         
     };
     String negTest[] = {
         "3ht://",
         "http:/",
         "http:",
         "http/",
         "://",
         ""

     };
     for(String ptest: posTest) {
         System.out.println("Test : "+ ptest);
         if (url.isValid(ptest + "go.com")){
             System.out.println("Passed Positive Test case.");
             pPass++;
         } else {
             System.out.println("Failed Positive Test case.");
             pFail++;
         }
     }
     for(String ntest: negTest) {
  	   System.out.println("Test : "+ ntest);
         if (!url.isValid(ntest + "go.com")){
             System.out.println("Passed Negative Test case.");
             fPass++;
         } else {
             System.out.println("Failed Positive Test case.");
             fFail++;
         }
     }
     System.out.println("\nTesting Complete \n");
     System.out.printf("Positive Test Passed : %d, Positive Test Failed: %d%n%n", pPass, pFail);
     System.out.printf("Negative Test Passed : %d, Negative Test Failed: %d%n%n", fPass, fFail);

 }
   
   public void testYourSecondPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   System.out.println("\nTest Authority in Urls.\n");
       int pFail=0, pPass=0,fFail=0, fPass=0;   // pFail = positive test fail , pPass = positive test pass
       // fFail = negative test fail, fPass = negative test fail.
       UrlValidator url = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

       String posTest[] = {
    	   "go.com",
           "google.com",
           "www.google.com.",
           "255.com",
           "0.0.0.0",
           "255.255.255.255"
       };
       String negTest[] = {
           "1.2.3.4.5",
           ".1.2.3.4",
           "go.a1a",
           "go.1aa",
           ".aaa",
           ""

       };
       for(String ptest: posTest) {
           System.out.println("Test : "+ ptest);
           if (url.isValid("http://" + ptest)){
               System.out.println("Passed Positive Test case.");
               pPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               pFail++;
           }
       }
       for(String ntest: negTest) {
    	   System.out.println("Test : "+ ntest);
           if (!url.isValid("http://" + ntest)){
               System.out.println("Passed Negative Test case.");
               fPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               fFail++;
           }
       }
       System.out.println("\nTesting Complete \n");
       System.out.printf("Positive Test Passed : %d, Positive Test Failed: %d%n%n", pPass, pFail);
       System.out.printf("Negative Test Passed : %d, Negative Test Failed: %d%n%n", fPass, fFail);
	   
	   
	   
	   
   }
   
   
   //You need to create more test cases for your Partitions if you need to 
   public void testYourThirdPartition()
   {
	   System.out.println("\nTest Path in Urls.\n");
       int pFail=0, pPass=0,fFail=0, fPass=0;   // pFail = positive test fail , pPass = positive test pass
       // fFail = negative test fail, fPass = negative test fail.
       UrlValidator url = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

       String posTest[] = {
    	   "/test1",
           "/t123",
           "/$23",
           "/test1/file",
           "",
           "/test1/"
       };
       String negTest[] = {
    	   "/..",
           "/../",
           "/..//file",
           "/test1//file"
           

       };
       for(String ptest: posTest) {
           System.out.println("Test : "+ ptest);
           if (url.isValid("http://255.255.255.255" + ptest)){
               System.out.println("Passed Positive Test case.");
               pPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               pFail++;
           }
       }
       for(String ntest: negTest) {
    	   System.out.println("Test : "+ ntest);
           if (!url.isValid("http://255.255.255.255" + ntest)){
               System.out.println("Passed Negative Test case.");
               fPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               fFail++;
           }
       }
       System.out.println("\nTesting Complete \n");
       System.out.printf("Positive Test Passed : %d, Positive Test Failed: %d%n%n", pPass, pFail);
       System.out.printf("Negative Test Passed : %d, Negative Test Failed: %d%n%n", fPass, fFail);
	   
   }
   
   public void testYourFourthPartition()
   {
	   System.out.println("\nTest Port in Urls.\n");
       int pFail=0, pPass=0,fFail=0, fPass=0;   // pFail = positive test fail , pPass = positive test pass
       // fFail = negative test fail, fPass = negative test fail.
       UrlValidator url = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

       String posTest[] = {
    	   ":80",
           ":65535",
           ":0"
       };
       String negTest[] = {
    	   ":65536",
           ":-1",
           ":65636",
           ":65a"
           

       };
       for(String ptest: posTest) {
           System.out.println("Test : "+ ptest);
           if (url.isValid("http://www.google.com" + ptest)){
               System.out.println("Passed Positive Test case.");
               pPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               pFail++;
           }
       }
       for(String ntest: negTest) {
    	   System.out.println("Test : "+ ntest);
           if (!url.isValid("http://www.google.com" + ntest)){
               System.out.println("Passed Negative Test case.");
               fPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               fFail++;
           }
       }
       System.out.println("\nTesting Complete \n");
       System.out.printf("Positive Test Passed : %d, Positive Test Failed: %d%n%n", pPass, pFail);
       System.out.printf("Negative Test Passed : %d, Negative Test Failed: %d%n%n", fPass, fFail);
	   
   }
   
   public void testYourFifthPartition()
   {
	   System.out.println("\nTest URL Query in Urls.\n");
       int pFail=0, pPass=0,fFail=0, fPass=0;   // pFail = positive test fail , pPass = positive test pass
       // fFail = negative test fail, fPass = negative test fail.
       UrlValidator url = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

       String posTest[] = {
    	   "?action=view",
           "?action=edit&mode=up",
           ""
         
       };
       
       for(String ptest: posTest) {
           System.out.println("Test : "+ ptest);
           if (url.isValid("http://www.google.com" + ptest)){
               System.out.println("Passed Positive Test case.");
               pPass++;
           } else {
               System.out.println("Failed Positive Test case.");
               pFail++;
           }
       }
       
       System.out.println("\nTesting Complete \n");
       System.out.printf("Positive Test Passed : %d, Positive Test Failed: %d%n%n", pPass, pFail);
       //System.out.printf("Negative Test Passed : %d, Negative Test Failed: %d%n%n", fPass, fFail);
	   
   }
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
