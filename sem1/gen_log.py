import time
import random

status = ["200 OK", "202 REDIRECT", "403 FORBIDDEN", "404 NOT FOUND", "500 INTERNAL ERROR"]
user = ["root", "lexolordan", "ivan_arhipov", "guest", "vasya_morozov", "tema_lebedev", "edgar_shmavonyan"]
for i in range(1000):
    status_i = random.randint(0, len(status) - 1)
    user_i = random.randint(0, len(user) - 1)
    print(time.time(), user[user_i], "SOME COMPLAIN INFO \"LOG DEBUG\"", status[status_i], "SOME COMPLAIN_END")
