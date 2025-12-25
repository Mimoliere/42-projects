# Born2beroot

## Prototype

This project does not involve coding a program or a library.
The goal is to install, configure and harden a virtual machine running a GNU/Linux distribution (I chose Debian) according to a strict set of rules and we must be able to explain every part of it and justify every choice we made for it.

The final “deliverable” is:
- A correctly configured virtual machine
- A defense session with a pair where you explain and justify your configuration

This project wasn't a lot of fun for me.
I didn't want to use old students's guides or AI to speedrun the subject so i googled nearly every notion to challenge myself a little bit, it was long and pretty boring.
I ended up checking a student's guide on Github for the cron script because it was a delicate part and I didn't want to fail my project for a small error, I also verified that all the things I did before were correct (they were !).
The defense sessions were pretty fun, people that corrected me were cool and helped me with the notions that I didn't mastered yet.

---

## Behavior

The configured virtual machine must:

- **Boot on a Debian-based system** installed from a minimal ISO, with:
  - Correct hostname
  - Correct partitioning scheme (LVM)
- **Enforce strong security policies**, including:
  - Strong password policy (length, complexity, expiration, history, lockout)
  - Limited `sudo` usage, with logging of commands
  - Proper user and group management (root, primary user, and additional users if required)
- **Provide basic network and service configuration**:
  - SSH service configured securely (e.g. port, root login disabled, etc.)
  - UFW or equivalent firewall configured with strict rules
- **Expose system monitoring information** via:
  - A `monitoring.sh` script run by `cron` every 10 minutes
  - Display of CPU/RAM/partition usage, active TCP connections, user logins, etc.

---

## Files

Most of the work is done inside the VM.

I may add the signature of the VM, screens or the cron script (if I remember to do it when I'm at school).

---

## Compilation

There is no compilation step for this project.

---

## Notes (eventually)

- This is mainly a **system administration and security** project:
  - Understanding how Linux authentication, permissions, and services work.
  - Learning basic hardening techniques and best practices.
- There is no “codebase” to show, but you should be able to:
  - Explain each configuration choice during the defense.
  - Show where and how password policies are enforced.
  - Justify your partition scheme and security decisions.
- Keeping a `notes.md` with commands and rationales is very helpful to:
  - Prepare for defense.
  - Reproduce the setup later.