add some file, then commit, then error:
	error: bad index file sha1 signature
	fatal: index file corrupt

solution:
$ rm -f .git/index
$ git reset

but error still appear.

gavin@ubuntu:/mnt/hgfs/ShareFolder$ git clone git@github.com:gavinshao111/cloudNote.git            
Cloning into 'cloudNote'...
fatal: 'origin' does not appear to be a git repository
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
