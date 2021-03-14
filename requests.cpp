#include <string.h>
#include "esp_log.h"
#include "esp_http_client.h"
#include "requests.h"
using namespace std;
#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048
static const char *TAG = "HTTP_CLIENT";
const char *RESPONSE_DATA = {};
int RESPONSE_DATA_LEN;
char local_response_buffer[MAX_HTTP_OUTPUT_BUFFER] = {0};

esp_err_t _http_event_handle(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ERROR:
        ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER");
        printf("%.*s", evt->data_len, (char *)evt->data);
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
        if (!esp_http_client_is_chunked_response(evt->client))
        {
              RESPONSE_DATA = (char *)evt->data;
              RESPONSE_DATA_LEN =  evt->data_len;
          
        }

        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        break;
    }
    return ESP_OK;
}

string Requests::get(string webserver, string webpath, string params)
{
    esp_http_client_config_t config = {
        .host = webserver.c_str(),
        .path = webpath.c_str(),
        .query = params.c_str(),
         .method = HTTP_METHOD_GET,
        .event_handler = _http_event_handle,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    // GET
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }
    ESP_LOG_BUFFER_HEX(TAG, local_response_buffer, strlen(local_response_buffer));
    esp_http_client_cleanup(client);

    return RESPONSE_DATA;
}

string Requests::post(string webserver, string webpath, string params, string body)
{
    esp_http_client_config_t config = {
        .host = webserver.c_str(),
        .path = webpath.c_str(),
        .query = params.c_str(),
        .method = HTTP_METHOD_POST,
        .event_handler = _http_event_handle,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    // POST
        const char *post_data = body.c_str();
    esp_http_client_set_header(client, "HeaderKey", "HeaderValue");
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }
    ESP_LOG_BUFFER_HEX(TAG, local_response_buffer, strlen(local_response_buffer));
    esp_http_client_cleanup(client);

    return RESPONSE_DATA;
}

 string Requests::put(string webserver, string webpath, string params,  string body)
{
    esp_http_client_config_t config = {
        .host = webserver.c_str(),
        .path = webpath.c_str(),
        .query = params.c_str(),
        .method = HTTP_METHOD_PUT,
        .event_handler = _http_event_handle,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    // PUT
    const char *post_data = body.c_str();
    esp_http_client_set_header(client, "HeaderKey", "HeaderValue");
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }
    ESP_LOG_BUFFER_HEX(TAG, local_response_buffer, strlen(local_response_buffer));
    esp_http_client_cleanup(client);

    return RESPONSE_DATA;
}

 string Requests::patch(string webserver, string webpath, string params,  string body)
{
    esp_http_client_config_t config = {
        .host = webserver.c_str(),
        .path = webpath.c_str(),
        .query = params.c_str(),
        .method = HTTP_METHOD_PATCH,
        .event_handler = _http_event_handle,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    // PATCH
    const char *post_data = body.c_str();
    esp_http_client_set_header(client, "HeaderKey", "HeaderValue");
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }
    ESP_LOG_BUFFER_HEX(TAG, local_response_buffer, strlen(local_response_buffer));
    esp_http_client_cleanup(client);
    return RESPONSE_DATA;
}

 string Requests::del(string webserver, string webpath, string params)
{
    esp_http_client_config_t config = {
        .host = webserver.c_str(),
        .path = webpath.c_str(),
        .query = params.c_str(),
        .method = HTTP_METHOD_DELETE,
        .event_handler = _http_event_handle,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    // Delete
    esp_http_client_set_header(client, "HeaderKey", "HeaderValue");
    esp_http_client_set_header(client, "Content-Type", "application/json");
    
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }
    ESP_LOG_BUFFER_HEX(TAG, local_response_buffer, strlen(local_response_buffer));
    esp_http_client_cleanup(client);
    return RESPONSE_DATA;
}

 string Requests::head(string webserver, string webpath, string params)
{
    esp_http_client_config_t config = {
        .host = webserver.c_str(),
        .path = webpath.c_str(),
        .query = params.c_str(),
        .method = HTTP_METHOD_HEAD,
        .event_handler = _http_event_handle,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    // Head
    esp_http_client_set_header(client, "HeaderKey", "HeaderValue");
    esp_http_client_set_header(client, "Content-Type", "application/json");
    
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP HEAD Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP HEAD request failed: %s", esp_err_to_name(err));
    }
    ESP_LOG_BUFFER_HEX(TAG, local_response_buffer, strlen(local_response_buffer));
    esp_http_client_cleanup(client);
    return RESPONSE_DATA;
}