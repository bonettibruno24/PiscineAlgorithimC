import uiautomator2 as u2

d = u2.connect("127.0.0.1:5555")

def open_app(app_name):
    if not d.app_wait(app_name, front=True, timeout=5):
        d.app_start(app_name)
        print("Abrindo... Aguarde 5 segundos")
        d.sleep(5)
    else:
        print(f"{app_name} já está aberto.")

open_app("com.dts.freefireth")

xml_dump = d.dump_hierarchy()
print(xml_dump) 

width , height = d.window_size()
print(f"Largura: {width}, Altura: {height}")


# d(resource-id"com.dts.freefireth:id/").click()
# d(description="Game view").click()


# apps = d.app_list()
# for app in apps:
#     print(app)
print(d.info)