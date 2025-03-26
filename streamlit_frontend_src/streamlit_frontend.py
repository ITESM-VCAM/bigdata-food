import requests as rq
import streamlit as sl
import json


def get_processed_dataset(file_url):
    response = rq.get(file_url)
    sl.write(response)
    if (response.status_code == 200):
        sl.write(response.json())


def post_github_dispatch(user, repo, job, token):
    url = f'https://api.github.com/repost/{user}/{repo}/dispatches'
    payload = {
        'event_type': job
    }
    headers = {
        'Authorization': 'Bearer ' + token,
        'Accept': 'application/vnd.github.v3+json',
        'Content-type': 'application/json'
    }
    sl.write(url)
    sl.write(payload)
    sl.write(headers)
    response = rq.post(url, json=payload, headers=headers)
    sl.write(response)


################
# Main program #
################

sl.title('Food Dataset Demo')
github_user = 'ITESM-VCAM'
sl.text(f'Current user: {github_user}')
github_repo = 'bigdata-food'
sl.text(f'Current repository: {github_repo}')
github_token = sl.text_input('Github token', value='')

sl.header('Data visualization')
file_url = sl.text_input(
    'File URL',
    value=f'https://github.com/{github_user}/{github_repo}/raw/refs/heads/master/results/FILENAME.json')
if sl.button('GET dataset file'):
    get_processed_dataset(file_url)

sl.header('Process data with Spark')
if sl.button('POST Spark-Processing'):
    post_github_dispatch(
        github_user, github_repo,
        'Spark-Processing', github_token
    )

sl.header('Generate new dataset')
if sl.button('POST Generate-Dataset'):
    post_github_dispatch(
        github_user, github_repo,
        'Generate-Dataset', github_token
    )
