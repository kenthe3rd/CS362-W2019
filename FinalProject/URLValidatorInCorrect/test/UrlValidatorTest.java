/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// URI schemes data from https://www.iana.org/assignments/uri-schemes/uri-schemes.xhtml

import junit.framework.TestCase;

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   // uses randomization on the first partition (scheme), holds other partitions constant 
   public void testYourFirstPartition(){
      UrlValidator urlValidator = new UrlValidator();
      int failureCounter = 0;
      System.out.println("TESTING SCHEME PARTITION");
      String[] validSchemes = {"aaa","aaas","about","acap","acct","cap","cid","coap","coap+tcp","coap+ws","coaps","coaps+tcp","coaps+ws","crid","data","dav","dict","dns","example","file","ftp","geo","go","gopher","h323","http","https","iax","icap","im","imap","info","ipp","ipps","iris","iris.beep","iris.lwz","iris.xpc","iris.xpcs","jabber","ldap","leaptofrogans","mailto","mid","msrp","msrps","mtqp","mupdate","news","nfs","ni","nih","nntp","opaquelocktoken","pkcs11","pop","pres","reload","rtsp","rtsps","rtspu","service","session","shttp","sieve","sip","sips","sms","snmp","soap.beep","soap.beeps","stun","stuns","tag","tel","telnet","tftp","thismessage","tip","tn3270","turn","turns","tv","urn","vemmi","vnc","ws","wss","xcon","xcon-userid","xmlrpc.beep","xmlrpc.beeps","xmpp","z39.50r","z39.50s"};
      String validEverythingBesidesScheme = "://www.google.com/search?source=hp&ei=ts56XMTHJNeE-gTuv4WgBw&q=java&btnK=Google+Search&oq=java&gs_l=psy-ab.3..35i39l2j0i67l8.4229.4503..4734...1.0..0.69.325.5......0....1..gws-wiz.....6..0i131j0.UP-xeLeZftI";
      for( int i=0; i<1000; ++i ){
         int stringIsValidScheme = 0;
         //generate a random string
         int stringLength =  (int) (Math.random() * 10);
         String scheme = "";
         for( int j=0; j<stringLength; ++j ){
            char character = (char) ((int) (Math.random() * 93) + 33);
            scheme = scheme + character;
         }
         //loop through the validSchems array to see if the string is a valid scheme
         for( int j=0; j<validSchemes.length; ++j ){
            if( validSchemes[j] == scheme ){
               stringIsValidScheme = 1;
               break;
            }
         }
         //append the known valid else to it
         String url = scheme + validEverythingBesidesScheme;
         //if it is a valid scheme, assert true, else assert false
         if( stringIsValidScheme == 1 ){
            if( urlValidator.isValid(url) == false ){
               //System.out.println("Unexpected invalid: " + url);
               failureCounter++;
            } 
         } else {
            if( urlValidator.isValid(url) == true ){
               //System.out.println("Unexpected valid: " + url);
               failureCounter++;
            }
         }
      }
      System.out.println("FAILURES: " + Integer.toString(failureCounter));
   }
   
   // uses randomization on the second partition (authority), holds other partitions constant 
   public void testYourSecondPartition(){
      int failureCounter = 0;
      UrlValidator urlValidator = new UrlValidator();
      System.out.println("TESTING AUTHORITY PARTITION");
      String validEverythingAfterAuthority = "/search?source=hp&ei=ts56XMTHJNeE-gTuv4WgBw&q=java&btnK=Google+Search&oq=java&gs_l=psy-ab.3..35i39l2j0i67l8.4229.4503..4734...1.0..0.69.325.5......0....1..gws-wiz.....6..0i131j0.UP-xeLeZftI";
      for( int i=0; i<1000; ++i ){
         int stringIsValidAuthority = 1;
         String authority = "";
         int authorityType = (int) (Math.random() * 1000) % 2;
         if( authorityType == 0 ){
            //TOTALLY RANDOM STRING FOR AUTHORITY 
            //choose a random authority length
            int stringLength = (int) (Math.random() * 64);
            for( int j=0; j<stringLength; ++j ){
               char character = (char) ((int) (Math.random() * 25) + 97);
               authority = authority + character;
            }
            //randomly determine whether we complete valid authority with leading scheme 'http://', if authority is otherwise valid
            if(stringIsValidAuthority == 1){
               stringIsValidAuthority = ((int) (Math.random() * 100)) % 2;
            }

            if(stringIsValidAuthority == 1){
               String url = "http://www." + authority + ".com" + validEverythingAfterAuthority;
               if( urlValidator.isValid(url) == false){
                  //System.out.println("Unexpected invalid: " + url);
                  failureCounter++;
               }
            } else {
               String url = "http" + authority + validEverythingAfterAuthority;
               if( urlValidator.isValid(url) == true){
                  //System.out.println("Unexpected valid: " + url);
                  failureCounter++;
               }
            }
         } else if( authorityType == 1 ){
            //TEST IN IPv4 NOTATION
            int buildValidIP = (int) (Math.random() * 100) % 2;
            int isValidIP = 1;
            for( int j=0; j<4; ++j ){
               int ip = (int) (Math.random() * 10000);
               if( buildValidIP == 1 ){
                  ip = ip % 256;
               }
               if( ip < 0 || ip > 255 ){
                  isValidIP = 0;
               }
               authority = authority + Integer.toString(ip);
               if( j != 3 ){
                  authority = authority + '.';
               }
            }
            String url = "http://" + authority + '/';
            if( isValidIP == 1 && urlValidator.isValid(url) == false ){
               //System.out.println("Unexpected invalid: " + url);
               failureCounter++;
            } else if( isValidIP == 0 && urlValidator.isValid(url) == true ){
               //System.out.println("Unexpected invalid: " + url);
               failureCounter++;
            }
         }
      }
      System.out.println("FAILURES: " + Integer.toString(failureCounter));
   }
   
   // uses randomization on the third partition (port), holds other partitions constant 
   public void testYourThirdPartition(){
      int failureCounter = 0;
      System.out.println("TESTING PORT PARTITION");
      String validSchemeAndHost = "http://www.google.com:";
      String validPath = "/";
      UrlValidator urlValidator = new UrlValidator();
      int portIsNumbersOnly = 1;
      for( int i=0; i<100000; ++i ){
         int stringLength = (int) (Math.random() * 16) + 1;
         String port = "";
         portIsNumbersOnly = 1;

         for( int j=0; j<stringLength; ++j ){
            int ascii = (int) (Math.random() * 94) + 32;
            if( ascii < 48 || ascii > 57 ){
               portIsNumbersOnly = 0;
            }
            char character = (char) ascii;
            port = port + character;
         }

         String url = validSchemeAndHost + port + validPath;
         if( portIsNumbersOnly == 1 ){
            int portInt = Integer.parseInt(port);
            if(portInt > 65535 || portInt < 0){
               if( urlValidator.isValid(url) == true){
                  //System.out.println("Unexpected valid: " + url);
                  failureCounter++;
               }
            } else {
               if( urlValidator.isValid(url) == false){
                  //System.out.println("Unexpected invalid: " + url);
                  failureCounter++;
               }
            }
         } else {
            if( urlValidator.isValid(url) == true){
               //System.out.println("Unexpected valid: " + url);
               failureCounter++;
            }
         }
      }
      System.out.println("FAILURES: " + Integer.toString(failureCounter));
   }
   
   // uses randomization on the fourth partition (path), holds other partitions constant 
   public void testYourFourthPartition() {
      int failureCounter = 0;
      System.out.println("TESTING PATH PARTITION");
      UrlValidator urlValidator = new UrlValidator();
   }
   
   // uses randomization on the fifth partition (query), holds other partitions constant 
   public void testYourFifthPartition(){
      int failureCounter = 0;
      System.out.println("TESTING QUERY PARTITION");
      String validEverythingBesidesQuery = "http://www.google.com/search?";
      UrlValidator urlValidator = new UrlValidator();
      for( int i=0; i<100000; ++i ){
         int buildValidQuery = (int) (Math.random() * 1000) % 2;
         String query = "";
         String url = "";
         if( buildValidQuery == 1 ){
            // BUILD A VALID QUERY
            int numArgs = (int) (Math.random() * 32) + 1; 
            for( int j=0; j<numArgs; ++j ){
               if( j != 0 ){
                  query = query + '&';
               }
               int keyLength = (int) (Math.random() * 31) + 1;
               int valueLength = (int) (Math.random() * 31) + 1;
               String key = "";
               String value = "";
               for( int k=0; k<keyLength; ++k ){
                  char character = (char) ((int) (Math.random() * 25) + 97);
                  key = key + character;
               }
               int valueType = (int) (Math.random() * 100) % 2;
               if( valueType == 0 ){
                  // BUILD A STRING VALUE
                  for( int k=0; k<valueLength; ++k ){
                     char character = (char) ((int) (Math.random() * 25) + 97);
                     value = value + character;
                  }
               } else if( valueType == 1 ){
                  // BUILD A NUM VALUE
                  int valNum = (int) Math.random() * 999999;
                  value = Integer.toString(valNum);
               }
               query = query + key + '=' + value;
            }
            url = validEverythingBesidesQuery + query;
            if( urlValidator.isValid(url) == false ){
               failureCounter++;
            }
         } else {
            // BUILD SOME GARBAGE
            int stringLength = (int) (Math.random() * 128);
            for( int j=0; j<stringLength; ++j ){
               char character = (char) ((int) (Math.random() * 25) + 97);
               query = query + character;
            }
            url = validEverythingBesidesQuery + query;
            if( urlValidator.isValid(url) == true ){
               failureCounter++;
            }
         }
      }
      System.out.println("FAILURES: " + failureCounter);
   }
}
