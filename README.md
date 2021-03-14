# Monkey Resquest


Componente de request, feito com intuito de deixar mais fácil a comunicação via api com o esp32
# Importação

Basta clonar este repositorio para a pasta [esp]/esp-idf/components

` https://github.com/KelvinyHenrique/mkrequest.git `


# Exemplo

```c++

  string body = "{\"temperatura\":\"25\"}";
  string webserver = "httpbin.org";
  string webpath = "/post";
  string params = "nome=kelviny&sobrenome=henrique";
  Requests *request = new Requests();
  cout << request->get(webserver, webpath, params) << std::endl;
  cout << request->post(webserver, webpath, params, body) << std::endl;
  cout << request->put(webserver, webpath, params, body) << std::endl;
  cout << request->patch(webserver, webpath, params, body) << std::endl;
  cout << request->del(webserver, webpath, params) << std::endl;
  cout << request->head(webserver, webpath, params) << std::endl;

```

#Repositorio de Exemplo

Basta clonar(Lempre-se de importar a biblioteca executando o passo acima) este repositorio para quaquer pasta
` https://github.com/KelvinyHenrique/Monkey-Request_Example.git `
Não esqueça de adicionar as credenciais de sua rede em SDKCONFIG ou então executar idf.py menuconfig e 
ir em Example Connection Configuration Exaplme > Wifi SSD e Wifi Password
 

```powershell
idf.py -p [PORTA] build flash monitor
```
