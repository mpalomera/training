

#ifndef __UTEST__
#define __UTEST__

#define GREEN "\033[32;1m"
#define RED "\033[31;1m"
#define RESET "\033[0m"
#define FAILED  "Failed. Error: "
#define PASSED  "Passed."
#define assert_test(message, test)\
  do {\
      if (!(test)) return message; \
    } while (0)

#define run_test(testname,test)\
  do {\
      char *message = test(); \
      if (message) \
        printf("\t %s \t ... \t %s %s %s %s\n",\
        testname,RED,FAILED, message,RESET); \
      else\
        printf("\t %s \t ... \t %s %s %s\n",\
        testname,GREEN,PASSED,RESET); \
    } while (0)

#endif