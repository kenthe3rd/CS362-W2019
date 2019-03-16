

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
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("Testing Manually.\n");
	   Boolean resultTest;
	   String url = "http://www.google.com";
	   resultTest = urlVal.isValid(url);
	   System.out.println(url+ " result: " + resultTest + "\n");
	   String url2 = "http/go.a1a";
	   resultTest = urlVal.isValid(url2);
	   System.out.println(url2+ " result: " + resultTest + "\n");
	   String url3 = "http://go.a1a:80";
	   resultTest = urlVal.isValid(url3);
	   System.out.println(url3+ " result: " + resultTest + "\n");
	   String url4 = "ftp://www.google.com";
	   resultTest = urlVal.isValid(url4);
	   System.out.println(url4+ " result: " + resultTest + "\n");
	   String url5 = "https://www.google.com";
	   resultTest = urlVal.isValid(url5);
	   System.out.println(url5+ " result: " + resultTest + "\n");
	   String url6 = "http://256.256.256.256";
	   resultTest = urlVal.isValid(url6);
	   System.out.println(url6+ " result: " + resultTest + "\n");
	   String url7 = "http://255.255.255.255:-1";
	   resultTest = urlVal.isValid(url7);
	   System.out.println(url7+ " result: " + resultTest + "\n");
	   String url8 = "//www.google.com";
	   resultTest = urlVal.isValid(url8);
	   System.out.println(url8+ " result: " + resultTest + "\n");
	   String url9 = "http://www.amazon.com/../";
	   resultTest = urlVal.isValid(url9);
	   System.out.println(url9+ " result: " + resultTest + "\n");
	   String url10 = "http://255.255.255.255:0";
	   resultTest = urlVal.isValid(url10);
	   System.out.println(url10+ " result: " + resultTest + "\n");
	   String url11 = "http://255.255.255.255:80";
	   resultTest = urlVal.isValid(url11);
	   System.out.println(url11+ " result: " + resultTest + "\n");
	   
   }
   
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
