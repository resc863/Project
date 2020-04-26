from selenium import webdriver
 
driver = webdriver.Chrome('chromedriver')
driver.get("https://www.youtube.com/")

driver.find_element_by_xpath('/html/body/ytd-app/div/div/ytd-masthead/div[3]/div[3]/div[2]/ytd-button-renderer/a').click()

driver.find_element_by_id('identifierId').send_keys(')

driver.find_element_by_css_selector('.RveJvd').click()
driver.find_element_by_css_selector("input[type=password]").send_keys('')

driver.find_element_by_css_selector('.CwaK9').click()
 
