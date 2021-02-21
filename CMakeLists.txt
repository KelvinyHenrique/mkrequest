idf_component_register(SRCS "requests.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES "nvs_flash" "protocol_examples_common" "esp_http_client" "esp-tls"
                    )