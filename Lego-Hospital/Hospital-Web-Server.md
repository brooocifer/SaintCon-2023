# Hospital Web Server

The Hospital Web Server was a (Dell) Wyse C90LEW thin client that cost $26.77 - https://www.ebay.com/itm/314105462192. See Billboard-Web-Server.md. Once I had set up the Billboard Web Server using the free hardware given to me by a friend, I wanted to replicate the web server as closely as possible for the hospital web server. I could not find identical hardware, but the C90LEW hardware was close enough. 
Similar to the Billboard Web Server, I installed the only version of Linux on it that appears to run on that hardware: Slacko Puppy Linux 5.7.0 - https://distrowatch.com/?newsid=08342 - from 2014. It runs Hiawatha Web Server version 8.6. The web pages hosted on it are all CGI perl script. This system was modified during conference setup on Monday, and also slightly during the conference as we hit a few bugs or needed to make minor changes to the CGI scripts to make the "hacked by" web page look better on the large displays monitors. These changes were made via SSH, using nano and vi editors. So changes were made on the fly in production. Do not recommend.

- Wyse C90LEW
- IP Address: 192.168.1.2
- Slacko Puppy Linux 5.7.0
- OpenSSH 6.1p1
- Hiawatha Web Server 8.6
- Hostname: STCONDC

Rebuild:
- Initial install: https://aubreykloppers.wordpress.com/2015/10/14/puppy-linux-on-wyse-c50le/ and https://aubreykloppers.wordpress.com/2014/11/12/puppylinux-on-wyse-c50le-device/
- passwd as root to set root password
- Setup network using icon on lower right, Internet connectivity required for software install
- Use Puppy Package Manager to install OpenSSH and nano
- Setup network to private network using icon on lower right, static IP
- Copy/Replace files:
- /etc/motd
- /etc/sshbanner
- /etc/hiawatha/hiawatha.conf
- /root/.config/autostart/sshd.desktop
- /root/.config/autostart/xhiawatha.desktop
- All files in /root/Web-Server (make sure to chmod a+x *.pl and chmod a+w *.dat)
- Run firewall configuration wizard - Custom, enable ports 22 (ssh) and 80 (http)

- ssh root@192.168.1.2
- hiawatha.run restart
- ls -l /root/Web-Server

File list to follow in later version
