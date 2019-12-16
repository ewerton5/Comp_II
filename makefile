
all:
	git pull
	git add *
	git commit -m "$(coment)"
	git push origin $(branch)