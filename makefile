
all:
	git config --global credential.helper cache
	git pull
	git add *
	git commit -m "$(coment)"
	git push origin $(branch)