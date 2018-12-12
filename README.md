#  Boost2XCTest

This project demonstrates how to easily integrate an existing unit test suite written for the Boost Test framework with Xcode and the XCTest framework. It allows leveraging Xcode's testing capabilities and visual tooling such as the test navigator UI, inline reporting of failures, debugging the test cases, etc.

The typical use case for this project is a C/C++ library that is shared across various platforms (eg. iOS and Android), and which has its own set of unit tests written in C++ with Boost.Test. You may then want to be able to run those test cases on the iOS simulator or even on a real iOS device, and Boost2XCTest will make this super easy and convenient to do from within Xcode, in exactly the same way you'd run test cases written in Swift or Objective-C for the XCTest framework. Of course running the Boost test suite from the command line via `xcodebuild` will also work as you'd expect.

## How it works

Boost2XCTest is a custom Boost test runner that leverages the Objective-C runtime to dynamically generate a subclass of the `XCTestCase` class for each Boost test suite found, and a test method on it for each test case found within that suite. The XCTest framework will then take over and execute whatever  tests you've selected to run, which could be all of them, or just a few hand-picked ones, or all within a test suite, etc.

## Integration

Executing a Boost test suite with Xcode requires of two things: an _iOS Unit Test Bundle_ and a host iOS application. The test bundle must include all the source code for the Boost test cases, plus the `Boost2XCTest.mm` file. Naturally it must also link against the Boost framework or static library and against the library being tested. The host app or test launcher app is just an 'empty' application whose only function is to host the test bundle, thus a simple app created with the _Single View App_ template will do. Make sure to link the Unit Test bundle with the host app in the 'General' settings tab of the test bundle.

Once the integration is ready, simply tell Xcode to run the test cases (⌘U) and after the first full run, the Test Navigator view should show a list of test suites and their test cases. You may then click on any individual test case to have it executed, or do the same for an entire test suite. 

![boost2xctest-test-navigator](https://user-images.githubusercontent.com/851717/49867123-cea6d180-fe09-11e8-9e90-226a15a6d142.png)

## Caveats

* Each Boost test suite (eg: `BOOST_AUTO_TEST_SUITE(APITestSuite)`) must have a unique name, or else there will be name collisions between the generated `XCTestCase` subclasses. 
* The Xcode Test navigator UI will list all the test cases correctly but it will not automatically navigate to the source code of each test case upon clicking on them. This only works for failed test cases, once they've reported an error. I don't believe there's a public API in the XCTest framework to achieve this but it _might_ be possible to do it using private APIs. Haven't really investigated much about it yet.
* _Click-to-run_ on individual test cases from within the source code editor is not supported, since Xcode cannot recognize Boost test cases as XCTest test cases at compile time. Instead use the Test navigator UI to trigger the execution of one or multiple test cases.

## Links

* The idea for this project came from https://github.com/mattstevens/xcode-googletest/ which does the same thing but for a test suite written for Google Test.
