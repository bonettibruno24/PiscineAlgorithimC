from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

browser = webdriver.Firefox()
browser.get('http://www.facebook.com')
assert 'Facebook' in browser.title

browser.quit()

