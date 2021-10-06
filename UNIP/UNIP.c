// UNIP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "curl/curl.h"

int main()
{
    CURL* req = curl_easy_init();
    CURLcode res;
    if (req)
    {
        curl_easy_setopt(req, CURLOPT_URL, "www.queimadas.dgi.inpe.br/queimadas/users/dados_abertos/focos/10min/");
        curl_easy_setopt(req, CURLOPT_FOLLOWLOCATION, 1L);
//      curl_easy_setopt(req, CURLOPT_HTTPGET, "www.queimadas.dgi.inpe.br/queimadas/users/dados_abertos/focos/10min/");
        res = curl_easy_perform(req);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_operation() failed : %s\n", curl_easy_strerror(res));
        }
    }
    curl_easy_cleanup(req);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
