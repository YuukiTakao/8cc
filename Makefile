.PHONY: run-bash
run-bash:
	docker run -it -v /Users/yukitakao/go/github.com/YuukiTakao/9cc:/9cc -w /9cc compilerbook bash