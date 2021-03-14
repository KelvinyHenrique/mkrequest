
#ifndef REQUESTS_H_
#define REQUESTS_H_


#include <iostream>
using namespace std;

class Requests
{
private:
    

public:
    string get(string webserver, string webpath, string params);
    string post(string webserver, string webpath, string params, string body);
    string put(string webserver, string webpath, string params, string body);
    string patch(string webserver, string webpath, string params, string body);
    string del(string webserver, string webpath, string params);
    string head(string webserver, string webpath, string params);
};

#endif