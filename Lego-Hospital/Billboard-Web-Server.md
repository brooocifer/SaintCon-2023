# Billboard Web Server

The Billboard Web Server was a (Dell) Wyse C50LE thin client that cost me $0.00. It was given to me by a friend. I installed the only version of Linux on it that appears to run on that hardware: Slacko Puppy Linux 5.7.0 - https://distrowatch.com/?newsid=08342 - from 2014. It runs Hiawatha Web Server version 8.6. The web pages hosted on it are all CGI perl script. This whole system was set up prior to the conference, and there were no changes made to it during the conference. The system actually boots up to an X11 environment, but I set up an SSH server in case a remote connection was needed for any maintenance during the con.

- Wyse C50LE
- IP Address: 192.168.42.2
- Slacko Puppy Linux 5.7.0
- OpenSSH 6.1p1
- Hiawatha Web Server 8.6
- Hostname: EAZY

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

- ssh root@192.168.42.2
- hiawatha.run restart
- ls -l /root/Web-Server

admin.pl - EAZY Billboard Ltd. Admin Interface, used to update billboard content (index.pl)

- Logo Path: stconlogo.png
- Organization Name: St. Con Hospital
- Slogan: Every Hacker a Patient
- Admin Notes: Private wifi password is SooperSecre7!
- Password Field (unlabeled) and Apply/Update button
- Reset to Defaults button
- View Billboard (link)

index.default - HTML for index page (used for dev only)

index.pl - EAZY Billboard Ltd. web page, meta tag forces a refresh every 60 seconds. Reads the local data files and uses information from them to display the logo, organization name, and slogan. Contains an unauthenticated link to the admin page.

logo.dat - Data file, contains the filename of the current logo

logo.default - Data file, contains the default logo filename (stconlogo.png)

name.dat - Data file, contains the current organization name

name.default - Data file, contains the default organization name (St. Con Hospital)

notes.dat - Data file, contains the current administration notes

notes.default - Data file, contains the default administration notes (Private wifi password is SooperSecre7!)

reset.pl - Reads all of the *.default data files, and copies them to the *.dat files, resetting the Billboard to the default state.

slogan.dat - Data file, contains the current slogan text

slogan.default - Data file, contains the default slogan text (Every Hacker a Patient)

stconlogo.png - Default logo image file

update.pl - Updates all *.dat files from the Administration Interface form, if the proper password is provided. The password is hard-coded in the file itself.
