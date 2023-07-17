
(cl:in-package :asdf)

(defsystem "dataget-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Xymsg" :depends-on ("_package_Xymsg"))
    (:file "_package_Xymsg" :depends-on ("_package"))
    (:file "imdata" :depends-on ("_package_imdata"))
    (:file "_package_imdata" :depends-on ("_package"))
  ))