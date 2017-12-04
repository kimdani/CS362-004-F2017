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


import junit.framework.TestCase;
import java.util.ArrayList;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        
        ResultPair[] testScheme = {
            new ResultPair("http://", true),
            new ResultPair("ftp://", true),
            new ResultPair("://", false),
            new ResultPair("https://", true),
            new ResultPair("h3t://", true),
            new ResultPair("3ht://", false),
            new ResultPair("http:", false),
            new ResultPair("http/", false),
            new ResultPair("http:/", false),
            new ResultPair("", true)
        };

        ResultPair[] testAuthority = {
            new ResultPair("www.google.com", true),
            new ResultPair("go.com", true),
            new ResultPair("go.au", true),
            new ResultPair("0.0.0.0", true),
            new ResultPair("255.255.255.255", true),
            new ResultPair("256.256.256.256", false),
            new ResultPair("255.com", true),
            new ResultPair("1.2.3.4.5", false),
            new ResultPair("1.2.3.4.", false),
            new ResultPair("1.2.3", false),
            new ResultPair(".1.2.3.4", false),
            new ResultPair("go.a", false),
            new ResultPair("go.a1a", false),
            new ResultPair("go.cc", true),
            new ResultPair("go.1aa", false),
            new ResultPair("aaa.", false),
            new ResultPair(".aaa", false),
            new ResultPair("aaa", false),
            new ResultPair("", false)
        };

        ResultPair[] testPath = {
            new ResultPair("/test1", true),
            new ResultPair("/t123", true),
            new ResultPair("/$23", true),
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/test1/", true),
            new ResultPair("", true),
            new ResultPair("/test1/file", true),
            new ResultPair("/..//file", false),
            new ResultPair("/test1//file", false)
        };

        ResultPair[] testQuery = {
            new ResultPair("?action=view", true),
            new ResultPair("?action=edit&mode=up", true),
            new ResultPair("", true)
        };

        String testString;
        boolean expectedResult;
        boolean actualResult;
        int loopCounter = 1;
        ArrayList<String> failedTests = new ArrayList<String>();

        for (int i = 0; i < testScheme.length; i++)
        {
            for (int j = 0; j < testAuthority.length; j++)
            {
                for (int k = 0; k < testPath.length; k++)
                {
                    for (int l = 0; l < testQuery.length; l++)
                    {
                        testString = "";
                        expectedResult = true;
                        actualResult = false;
                        testString = testScheme[i].item + testAuthority[j].item + testPath[k].item + testQuery[l].item;
                        expectedResult = (testScheme[i].valid && testAuthority[j].valid && testPath[k].valid && testQuery[l].valid);
                        actualResult = urlVal.isValid(testString);

                        System.out.println("-----Iteration #" + loopCounter + ":-----");
                        System.out.println("TESTING: " + testString + "\nExpected: " + expectedResult + "\tActual: " + actualResult + "\n");
                        loopCounter++;

                        if (actualResult != expectedResult)
                        {
                            failedTests.add(testString);
                        }
                    }
                }
            }
        }

        System.out.println("\n\n-----Failed URLs:-----\n");
        for (int i = 0; i < failedTests.size(); i++)
        {
            System.out.println(failedTests.get(i));
        }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
