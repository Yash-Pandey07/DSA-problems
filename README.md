# DSA Problems

Welcome to the **DSA Problems** repository! This repository contains solutions to various Data Structures and Algorithms (DSA) problems. The solutions are implemented in **C++** and **Java**.

## Table of Contents

- Introduction
- Languages Used
- How to Use
- Contributing

## Introduction

In this repository, I solve and save solutions to different DSA questions. The aim is to provide clear and efficient solutions to common DSA problems.

## Languages Used

- **C++**
- **Java**


## How to Use

1. Clone the repository:
   ```sh
   git clone https://github.com/Yash-Pandey07/DSA-problems.git

## Contributing
Contributions are welcome! If you have a solution to a DSA problem that is not covered in this repository, feel free to create a pull request.


## Latest DSA News
!DSA Problems

Stay updated with the latest DSA news and problems:

```python
import requests
from bs4 import BeautifulSoup

def fetch_latest_dsa_news():
    url = 'https://www.geeksforgeeks.org/category/algorithm/'
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    articles = soup.find_all('article', class_='type-post')
    
    for article in articles[:5]:  # Fetch the latest 5 articles
        title = article.find('h2', class_='entry-title').text
        link = article.find('a')['href']
        print(f'Title: {title}\nLink: {link}\n')

fetch_latest_dsa_news()
```
